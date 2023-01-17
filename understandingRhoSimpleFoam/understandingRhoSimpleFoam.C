/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2023 OpenFOAM Foundation
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
    understandingRhoSimpleFoam

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "simpleControl.H"
#include "fluidThermo.H" //For Thermodynamics
#include "turbulentFluidThermoModel.H"   //For the turbulence model"
#include "pressureControl.H"



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
     
    #include "setRootCase.H"
    #include "createTime.H"  //It will be created from the controlDict 
    #include "createMesh.H"    
    #include "createControl.H"
  
    
     #include "createFields.H"
     
     
    turbulence->validate();
     
      // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    
    while(simple.loop(runTime))
    {
		Info<<"Time: "<<runTime.timeName()<<endl;
		
		// <convection term> - <diffusion term> == - <pressure gradient>
		 
		 //FVM=> finite volume Method=> Implicit Method
		 //FVC=> Finite VOlume Calculus=> Explicit Method  
		 
		   fvVectorMatrix UEqn
        (
            fvm::div(phi,U) + turbulence->divDevRhoReff(U) == -fvc::grad(p)
        );
		  	
		 UEqn.solve();  
		 
		 #include "EEqn.H"
		 
		 volScalarField A = UEqn.A();
		 volVectorField H = UEqn.H();
		 volScalarField rAU= 1.0/A; //A has only diagonal elemetns
		 
         surfaceScalarField rhorAUf("rhorAUf", fvc::interpolate(rho*rAU));
		 
		 volVectorField HbyA = rAU*H;
		 
		 surfaceScalarField phiHbyA("phiHbyA", fvc::interpolate(rho)*fvc::flux(HbyA));
		  
		   fvScalarMatrix pEqn
        (
            fvm::laplacian(rhorAUf, p) == fvc::div(phiHbyA)
        );
		 
		//Set refrence value for the pressure
        //pEqn.setReference(pRefCell, pRefValue);
		
		  pEqn.setReference
        (
            pressureControl.refCell(),
            pressureControl.refValue()
        );
		
		pEqn.solve();
		  	
		 //Relaxation Factor 
		 
		  p= alpha*p+ (1-alpha)*pold;	
		  	
		 //Update the value of U 	
		  
		 U=  HbyA- rAU* fvc::grad(p);
		 
		 phi = linearInterpolate(rho*U) & mesh.Sf();
		 
        U.correctBoundaryConditions();
        p.correctBoundaryConditions();
		  
		pold = p; 	
	
        rho = thermo.rho();  
        
        turbulence->correct();
        
        runTime.write();
      
       
		}


    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
        << nl << endl;

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
