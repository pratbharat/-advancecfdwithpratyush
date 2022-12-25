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
    understanding_mesh

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    //#include "setRootCase.H"
    
    Foam::argList args(argc, argv);
		if (!args.checkRootCase())
	{
		Foam::FatalError.exit();
	}
 
    
   // #include "createTime.H"
   Foam::Time runTime(Foam::Time::controlDictName, args);  //Constructor of Time class. 
  
  Info<< "Time name : "<< runTime.timeName()<<endl;
	//#include "createMesh.H"

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
		
	/*
	 1. Cell Size=> mesh.C().size()
	 2. face size=> mesh.Cf().size()
	 3. Cell centers of i cell => mesh.C()[i]
	 4. Neighbour=>mesh.neighbour().size()
	 5. Owner=>mesh.owner().size()
	 6. All faces=> mesh.faces()
	 7. All mesh points=> mesh.points()
	 8. face centers of all faces=> mesh.faceCentres();
	 9. Accessing All boundary=> mesh.boundary()
	  */	
	
	//Info<<"mesh has "<< mesh.C().size()<< "cells."<<endl;
	//Info<<"mesh has "<< mesh.Cf().size()<< "internal faces."<<endl;
	
	/*
    for (label i = 0; i < mesh.C().size(); i++)
           { Info << "Cell " << i << " with centre at " << mesh.C()[i] << endl;
            
            Info << "Cell " << i << " x coordinates " << mesh.C()[i].x() << endl;
            Info << "Cell " << i << " y coordinates " << mesh.C()[i].y() << endl;
            Info << "Cell " << i << " z coordinates " << mesh.C()[i].z() << endl;

		}
    Info << endl; // spacer
	*/
	/*
	// for (label i = 0; i < mesh.Cf().size(); i++)
	forAll(mesh.Cf(), i)
	{
		Info << "face " << i << " with centre at " << mesh.Cf()[i] << endl;
		
        Info << "face " << i << " x coordinates " << mesh.Cf()[i].x() << endl;
            
            Info << "Cell " << i << " x coordinates " << mesh.C()[i].x() << endl;
            Info << "Cell " << i << " y coordinates " << mesh.C()[i].y() << endl;
            Info << "Cell " << i << " z coordinates " << mesh.C()[i].z() << endl;
            
	}
	*/
	/*
	Info<<"Mesh neighbour size: "<<mesh.neighbour().size()<<endl;
	Info<<"Mesh owner size: "<<mesh.owner().size()<<endl;  //It always give access to internal faces.
	
	for (label faceI = 0; faceI < mesh.neighbour().size(); faceI++)
        {
            Info << "Internal face " << faceI << " with centre at " << mesh.Cf()[faceI]
                 << " with owner cell " << mesh.owner()[faceI]
                 << " and neighbour " << mesh.neighbour()[faceI] << endl;
			 }
    Info << endl;
    */
   
	
	/*
    forAll(mesh.boundaryMesh(), patchI)
      {   Info << "Patch " << patchI << ": " << mesh.boundary()[patchI].name() << " with "
             << mesh.boundary()[patchI].Cf().size() << " faces. Starts at total face "
             << mesh.boundary()[patchI].start() << endl;
		 }
    Info << endl;
    */
    /* 
    label patchFaceI(0);   //1,2,3 
    forAll(mesh.boundaryMesh(), patchI)
      {  Info << "Patch " << patchI << " has its face " << patchFaceI << " adjacent to cell "
             << mesh.boundary()[patchI].patch().faceCells()[patchFaceI]
             << ". It has normal vector " << mesh.boundary()[patchI].Sf()[patchFaceI]
             << " and surface area " << mag(mesh.boundary()[patchI].Sf()[patchFaceI])
             << endl;
		 }
    Info << endl; 
*/

 /*
	const faceList& faces = mesh.faces(); 
	
 // Store boundary mesh information
	const polyBoundaryMesh& boundaryMesh = mesh.boundaryMesh(); 
		// Loop over all faces (internal and boundary)
	forAll(faces, face)
	{
	  if (mesh.isInternalFace(face)) // Internal face is found
	  {
		// Do your calculations for internal faces i.e.
		// U[face] = vector::zero;
	}
	else                           // Boundary face is found
	{
		const label& patch = boundaryMesh.whichPatch(face);       // Boundary patch index
		const label& facei = boundaryMesh[patch].whichFace(face); // Local boundary face index
		
		// Do your calculations for boundary faces i.e.
		// U.boundaryField()[patch][facei] = vector::zero;
	}
	}
	


	// Loop over boundary patches
	forAll(mesh.boundary(), patch)
	{
		const word& patchName = mesh.boundary()[patch].name();            // Boundary patch name
    
		// Loop over all faces of boundary patch
		forAll(mesh.boundary()[patch], facei)
		{
			const label& bCell = boundaryMesh[patch].faceCells()[facei];    // Boundary cell index
			const label& face = boundaryMesh[patch].start() + facei;        // Face index
            Info<<"path: "<< patchName << "face "<<facei<<endl;
			// Do your calculations e.g.
			// U.boundaryField()[patch][facei] = vector::zero;
		}
    
		// Loop over all nodes of boundary patch
		forAll(boundaryMesh[patch].meshPoints(), pointi)
		{
			const label& point = boundaryMesh[patch].meshPoints()[pointi];  // Node index
           
			// Do your calculations e.g.
			// U[point] = vector::one;
	}
	}
*/
    /*
     label patchID(0);
    word patchName("maxZ");
    patchID = mesh.boundaryMesh().findPatchID(patchName);
    Info << patchName << " has index " << patchID  << endl;
*/
  
  //To access the volume of the cell and total volume.
  /*
  scalar sum=0;
  forAll(mesh.C(),i)
  {
	  Info<<"cell index "<<i<<" has volume: "<<mesh.V()[i]<<endl;
	  sum=sum+mesh.V()[i];
  }
      Info<<"The total volume of the mesh: "<<sum<<endl;

*/
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
/*
    Info<< nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
        << nl << endl;
*/
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
