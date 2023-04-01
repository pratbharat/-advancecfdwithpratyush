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
    class2

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

template <class T>
class complex_num{
	public:
	T r;
	T i;
	complex_num();
	complex_num(T,T);
    complex_num operator +(complex_num&);
	};
	
template <class T>	
complex_num<T>::complex_num()
{
	r = 1.0;
	i=2.0;
	}
	
template <class T>	
complex_num<T>::complex_num(T a,T b)
{
	r = a;
	i=b;
	}
	
template <class T>	
complex_num<T> complex_num<T>::operator +(complex_num& num1)
{
	complex_num result;
	result.r = r+num1.r;
	result.i = i+num1.i;
	return result;
	
}


//operator overloading a=1+2i ; b=2+7i ; a+b


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    complex_num <label> n1(1.0,2.0);
    complex_num <scalar> n2(4.2,1.3);
    complex_num <int> n3(5.2,0.3);
    complex_num <scalar> n4(3.2,8.3);
    
    complex_num <scalar>res= n2+n4;
    
    
    Info<< "The addition of complex numbers are: "<<n1.r<<"+"<<n1.i<<"i" << endl;
    Info<< "The addition of complex numbers are: "<<n2.r<<"+"<<n2.i<<"i" << endl;
    Info<< "The addition of complex numbers are: "<<n3.r<<"+"<<n3.i<<"i" << endl;
    Info<< "The addition of complex numbers are: "<<res.r<<"+"<<res.i<<"i" << endl;

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
