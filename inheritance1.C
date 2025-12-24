/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2024 OpenFOAM Foundation
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
    inheritance1

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

/*
pressure_drop=128*mu*Q*L/pi*D^4

Re= rho*Q*4/(pi*mu*D)

common terms- Q,D,mu
*/
class flow_in_pipe    // base class
{
	public:
	scalar mu,u,D;
	scalar Q();
	
	void Input_value(scalar,scalar,scalar);
};
class calc_pressure_drop: public flow_in_pipe// derived class
{
	public:
	scalar L;
	void Input_length(scalar e)
	{
		L =e;
	}
	scalar pressure_drop();
	
};

class calc_Re:public flow_in_pipe // derived class
{
	public:
	scalar rho;
	void Input_rho(scalar f)
	{
	    rho=f;
	}
	scalar Re();
};

void flow_in_pipe::Input_value(scalar a,scalar b,scalar c)
{
	mu=a;
	u=b;
	D=c;
	
}

scalar flow_in_pipe::Q()
{
	return ((3.14/4)*pow(D,2)*u);
}

scalar calc_pressure_drop::pressure_drop()
{
	return ((128*mu*Q()*L)/(3.14*pow(D,4)));
}

scalar calc_Re::Re()
{
	return ((4*rho*Q()*L)/(3.14*mu*D));
}

int main(int argc, char *argv[])
{
    calc_pressure_drop pipe1;
	pipe1.Input_value(1e-5,2,0.02);
	pipe1.Input_length(2);
	pipe1.Input_rho(1000);
	
	Info<<"Pressure_drop in pipe 1 is"<<pipe1.pressure_drop()<<endl;
	
	Info<<"Reynold's number for pipe 1 is"<<pipe1.Re()<<endl;
	


    return 0;
}


// ************************************************************************* //
