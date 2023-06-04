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
    objectRegistry

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"    // => objectRegistry
    
    
    
	Foam::fvMesh mesh
		(
			Foam::IOobject
			(
				Foam::fvMesh::defaultRegion,
				runTime.timeName(),
				runTime,
				Foam::IOobject::MUST_READ
			)
		);
		
		
		Info << nl << "Reading pressure field" << endl;
volScalarField p   //IODictionary 
(
 	IOobject
	(
	 	"p",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);


	Info << nl << "Reading Velocity field" << endl;
volVectorField U  //IODictionary 
(
 	IOobject
	(
	 	"U",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);
    
// time=> Mesh=> p, U 


     Info<< runTime.objectRegistry::names()<<endl;
     
     
     Info<< mesh.objectRegistry::names()<<endl;
     
     
     Info<< runTime.objectRegistry::db()<<endl;
     
     
     Info<< mesh.objectRegistry::db()<<endl;
     
     
     //
     /*
      //- Lookup and return the object of the given Type
             template<class Type>
             const Type& lookupObject(const word& name) const; */
             
             /*
             //- Is the named Type found?
             template<class Type>
             bool foundObject(const word& name) const;
*/
     

      volScalarField Pold = mesh.lookupObject<volScalarField>("p");
      
      Info<<"Pold: "<<Pold<<endl;

      Info<<"FInd out or not: "<<mesh.foundObject<volVectorField>("U");

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
