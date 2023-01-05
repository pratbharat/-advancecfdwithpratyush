/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2022 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    understandingSimpleFOAM

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H" 
#include "simpleControl.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
	/*
	 Steps: 1. Check the folder structure.
	 *      2. Create the time object.
	 *      3. Create the mesh object. 
	 *      4. Create the object for looping. So here we are using the simple loop which is simplest looping object. There are other loops 
	            are piso, pimple .
	 * 
	 *	  Assumptions:   
	 *      1. Steady State
	 *      2. Incompressible flow
	 *      3. Constant kinamatic viscocity  (Newtonian FLow)
	 *      4. Low Reynolds number
	 *      5. Neglect Body Forces 
	 * 
	 *    Modifications:
	 * 	    1. Kinamatic Pressure (P/rho) 
	 * 
	 *    SIMPLE Scheme: 
	        (i)  Solve U with previous pressure.
	        (ii) Calculate (A-1) (H)
	        (iii) Pressure-corrector Step 
	        (iv) Update U
	        (v) Update P
	 */
	
	
    #include "setRootCase.H"
   #include "createTime.H"  //It will be created from the controlDict 
   #include "createMesh.H"    
    #include "createControl.H"
  
     #include "createFields.H"
    //Info<<"Hello WOrld"<<endl;
   // #include "anyFIle"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    
    while(simple.loop(runTime))
    {
		Info<<"Time: "<<runTime.timeName()<<endl;
		
		// <convection term> - <diffusion term> == - <pressure gradient>
		 
		 //FVM=> finite volume Method=> Implicit Method
		 //FVC=> Finite VOlume Calculus=> Explicit Method  
		   fvVectorMatrix UEqn
        (
            fvm::div(phi,U) - fvm::laplacian(nu,U) == -fvc::grad(p)
        );
		  	
		 UEqn.solve();  
		 
		 volScalarField A = UEqn.A();
		 volVectorField H = UEqn.H();
		 
		 volScalarField A_inv= 1.0/A; //A has only diagonal elemetns
		 
		 volVectorField HbyA = A_inv*H;
		 
		 surfaceScalarField  A_inv_flux= fvc::interpolate(A_inv);
		 
		   fvScalarMatrix pEqn
        (
            fvm::laplacian(A_inv_flux, p) == fvc::div(HbyA)
        );
		 
		
		//Set refrence value for the pressure
        pEqn.setReference(pRefCell, pRefValue);
		
		pEqn.solve();
		  	
		 //Relaxation Factor 
		 
		  p= alpha*p+ (1-alpha)*pold;	
		  	
		 //Update the value of U 	
		  
		 U=  A_inv*H - A_inv* fvc::grad(p);
		 
		 phi = fvc::interpolate(U) & mesh.Sf();
		 
        U.correctBoundaryConditions();
        p.correctBoundaryConditions();
		  
		pold = p; 	
		 
        runTime.write();	
		}

       
       

    Info<< nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
        << nl << endl;
  
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
