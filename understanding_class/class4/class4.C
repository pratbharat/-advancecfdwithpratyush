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
    class1

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

/*
 Polymorphism:Many forms
 1. Complile Type Polymorphism (Function overloading, operator overloading)
 2. Run Time Polymorphism (virtual)
 */ 

//del P = 128*mu*Q*L/pi*d^4=> mu and Q,d
// Re = 4 Q/ (pi*D*mu)=> mu and Q,d

class fluid_flow{
	protected:
	scalar mu,u,d;
	public: 
	void set_values(scalar a,scalar b,scalar c)
	{
		mu=a;
		u=b;
		d=c;
	};
	/*
	void set_values(int a,int b,int c)
	{
		mu=a;
		u=b;
		d=c;
	};
	void set_values()
	{
		mu=1e3;
		u=2.0;
		d=3.0;
	};
	*/
	virtual void display()
	{
		Info<<"The value of viscosity: "<<mu<<endl;
		Info<<"The value of velocity: "<<u<<endl;
		Info<<"The value of diameter: "<<d<<endl;
		}
		
	scalar flowrate()
	{
		scalar area = (3.14/4)*pow(d,2);
		return u*area;
		};
};


class pressure_cal: public fluid_flow{
	private:
	scalar length;
	public:
	void set_length(scalar l)
	{
		length=l;
		};
	scalar Pressure_val(){
		return (128*mu*flowrate()*length)/(3.14*pow(d,4));
	};
	void display()
	{
		Info<<"The value of viscosity: "<<mu<<endl;
		Info<<"The value of velocity: "<<u<<endl;
		Info<<"The value of diameter: "<<d<<endl;
		Info<<"The value of length: "<<length<<endl;
		}
		
};
	 
/*
class reynolds_num: public fluid_flow{
	public:
	scalar cal_Re(){
		
		return (4*flowrate())/(3.14*d*mu);
	};
};
*/
	//4 Q/ (pi*D*mu)

	
	
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
	//pressure_cal press1;
	//press1.set_values(1e-5,1.2,3e-3);
	//press1.set_length (20e-2);
	//reynolds_num Re1;
	//Re1.set_values(1e-5,1.2,3e-3);
   /*
    fluid_flow f1;
    f1.set_values(1e-5,2.0,1e-3);
    f1.display();
    f1.set_values(1,2,1);
    f1.display();
    f1.set_values();
    f1.display();
    */
    fluid_flow* ftr;
    pressure_cal p1;
    ftr= &p1;    
    p1.set_values(1e-5,2.0,1e-3);
    p1.set_length (20e-2);
    ftr->display();    
    Info<< "End\n" << endl;
    return 0;
}


// ************************************************************************* //
