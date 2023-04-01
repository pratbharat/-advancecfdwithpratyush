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
 Three kind of members.
 private:accessible only from within other members of the same class
 protected:accessible from other members of the same class; 
 public:members are accessible from anywhere where the object is visible
 Note: By default all the member are private.
 */


//del P = 128*mu*Q*L/pi*d^4

class pressure_cal{
	private:
	scalar mu,u,length, dia;
	
	public:
	
	//void set_values(scalar ,scalar ,scalar ,scalar );
	//Constructor 
	pressure_cal();
	pressure_cal (scalar ,scalar ,scalar ,scalar );
	
	scalar flowRate(){
		scalar area = (3.14/4)*pow(dia,2);
		return u*area;
		}; 
	scalar Pressure_val(){
		
		return (128*mu*flowRate()*length)/(3.14*pow(dia,4));
	};
	 
	pressure_cal operator+ (pressure_cal&);
	};
/*	
void pressure_cal::set_values(scalar a,scalar b,scalar c,scalar d)
{
     mu = a;
     u=b;
     length=c;
     dia=d;
     	
	}
*/
pressure_cal::pressure_cal()
{
     mu = 1.2e-6;
     u=1;
     length=0.05;
     dia=0.002;
     	
	}

pressure_cal::pressure_cal(scalar a,scalar b,scalar c,scalar d)
{
     mu = a;
     u=b;
     length=c;
     dia=d;
     	
	}
	

	
	
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
  /*
    pressure_cal P;
    P.set_values(1e-5,2.0,0.020,0.003);
    Info<<"The pressure drop is: "<<P.Pressure_val()<<endl;
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //   
    Info<< "End\n" << endl;
    */
    /*
    pressure_cal P (1e-5,2.0,0.020,0.003);
    pressure_cal P1 ;
    Info<<"The pressure drop is: "<<P.Pressure_val()<<endl;
    Info<<"The pressure drop is: "<<P1.Pressure_val()<<endl;
    * 
    */
    //Initialization of the constructor 
    /*
    pressure_cal P1 (1e-5,2.0,0.020,0.003); 
    pressure_cal P2 = {1e-5,2.0,0.020,0.003};
    pressure_cal P3 {1e-5,2.0,0.020,0.003};
    
    
    Info<<"The pressure drop is: "<<P1.Pressure_val()<<endl;
    Info<<"The pressure drop is: "<<P2.Pressure_val()<<endl;
    Info<<"The pressure drop is: "<<P3.Pressure_val()<<endl;
    */
    // class to pointer
    //what is the pointer ?
    // Pointer: It is a kind of variable that stores the memory of created variable.
    /*
    scalar a=3.0;
    scalar * p; 
    p=&a;//&-> The adress of a.
    
    Info<<"The adress of a : "<<p<<endl; 
    Info<<"The adress of a: "<<&a<<endl;
    Info<<"The pointer p has value : "<<*p<<endl; 
    //p => It signifies => it pointed to 
   
     pressure_cal P1 (1e-5,2.0,0.020,0.003); 
     pressure_cal * ptr;
     ptr = &P1;
     
    Info<<"The pressure drop is: "<<ptr->Pressure_val()<<endl;  //->
    Info<<"The pressure drop is: "<<(*ptr).Pressure_val()<<endl;  //(*).
     */
    
   
    
    Info<< "End\n" << endl;
    return 0;
}


// ************************************************************************* //
