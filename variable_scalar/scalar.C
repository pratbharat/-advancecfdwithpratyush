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
    scalar

Description
   Scalar quantity 
\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

// #inluce "iostream.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
   // #include "setRootCase.H"  => to check folder structure  i.e whether 0, constant, system otherwise shows the error
   //  #include "createTime.H"   => To create the class of Time=> system/controlDict => It create the object of runTime.

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    
    scalar a=2.0, b=3.0, c=4.0;
    
    Info<<"a: "<<a <<" and b: "<<b<<" c:"<<c<<endl;
    Info<<"The sum: "<<(a+b+c)<<endl;
    Info<<"The Multiplication: "<<(a*b*c)<<endl;
    Info<<"The Division: "<<(a/c)<<endl;
    Info<<"The Subtraction: "<<(a-b-c)<<endl;
    
    
/*
    Info<< nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
        << nl << endl;
*/
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
