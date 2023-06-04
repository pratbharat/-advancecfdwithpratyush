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
    
    //T=> Mesh01, Mesh02=> 
    
	Foam::fvMesh mesh01
		(
			Foam::IOobject
			(
				"Fluid",
				runTime.timeName(),
				runTime,
				Foam::IOobject::MUST_READ
			)
		);
		
		
	Foam::fvMesh mesh02
		(
			Foam::IOobject
			(
				"Solid",
				runTime.timeName(),
				runTime,
				Foam::IOobject::MUST_READ
			)
		);
		
		
		
		Info << nl << "Reading pressure Fluid field" << endl;
new volScalarField   //IODictionary 
(
 	IOobject
	(
	 	"p",
		runTime.timeName(),
		mesh01,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh01
);



		Info << nl << "Reading pressure Solid field" << endl;
new volScalarField   //IODictionary 
(
 	IOobject
	(
	 	"p",
		runTime.timeName(),
		mesh02,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh02
);



	Info << nl << "Reading Velocity fluid field" << endl;
new volVectorField //IODictionary 
(
 	IOobject
	(
	 	"U",
		runTime.timeName(),
		mesh01,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh01
);
    
    
    
    Info << nl << "Reading Velocity Solid field" << endl;
new volVectorField   //IODictionary 
(
 	IOobject
	(
	 	"U",
		runTime.timeName(),
		mesh02,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh02
);


  
IOdictionary transportProperties
(
 	IOobject
	(
		"transportProperties",
		runTime.constant(),
		mesh01,
		IOobject::MUST_READ_IF_MODIFIED,
		IOobject::NO_WRITE
	)
);


dimensionedScalar nu
(
 	"nu",
	dimensionSet(0,2,-1,0,0,0,0),
	transportProperties
);

  
// Time=>(Mesh01, Mesh02)=> Mesh01(points,Fields,p,U,transportProperties) Mesh02(points,Fields,p,U)

     Info<< runTime.objectRegistry::names()<<endl;
     
     
     Info<< mesh01.objectRegistry::names()<<endl;
     
     
     Info<< mesh02.objectRegistry::names()<<endl;
     
     
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
     

      volScalarField Pold = mesh01.lookupObject<volScalarField>("p");
      
      Info<<"Pold: "<<Pold<<endl;

      Info<<"FInd out or not: "<<mesh02.foundObject<volVectorField>("U");

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
