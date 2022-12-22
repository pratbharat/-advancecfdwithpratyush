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
    variable_string

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "stringOps.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    //string test;
    
   // test = "    This is the the OpenFOAM tutorial.    "; 
    
   // Info<<test<<endl;
    /*
    Info<<"trimLeft: " << stringOps::trimLeft(test) << endl;
    Info<<"trimRight: " << stringOps::trimRight(test) << endl;
    Info<<"trim: " << stringOps::trim(test) << endl;
    */
    /*
    for (string::const_iterator i= test.begin(); i<= test.end();i++)
    {
		Info<<*i<<endl;
		
	}
	*/
	/*
    Info<<string(test).replace(" ","n")<<endl;    //Only Remove the first space character 
    Info<<string(test).replace(" ","")<<endl; // One way of removing spaces
    Info<<string(test).replaceAll("i","n")<<endl;  //Remove all the chr
    Info<<string(test).replaceAll(" ","")<<endl;   // The way of removing all the space char
    Info<<string(test).replaceAll("the","")<<endl;
    */ 
    /*
    string test2= "This tutorial we are running in $FOAM_RUN. The user is from $HOME." ;
    Info<<test2<<endl;
    Info<<test2.expand()<<endl;
    */ 
    
   // string test2= "This tutorial we are running in $FOAM_RUN. The user is from $HOME." ;
   /*
    dictionary dict;
    
    dict.add("HOME","myHome");
    
    dictionary subdict; 
    
    subdict.add("value1","val1");
    subdict.add("value2",3);
    
    dict.add("FOAM_RUN",subdict);
    
    Info<<dict<<endl;
    
    
  
    dictionary subdict2; 
    
    subdict2.add("type","fixedValue");
    subdict2.add("value","uniform 0");
    
    dict.add("inlet",subdict2);
    
    
    Info<<dict<<endl;
    */
   // Info<<test2<<endl;
    
   // Info<<test2.expand()<<endl;
    
   // string test3("~OpenFOAM/controlDict");
    //Info<< test3 << " => " << test3.expand() << endl;
    
    /*
     // replace controlDict with "newName"
    {
        string::size_type i = test3.rfind('/'); // If / is not present in the string; i=-1;

        if (i == string::npos)  //string::npos =-1
        {
            test3 = "newName";
        }
        else
        {
            // this uses the std::string::replace
            test3.replace(i+1, string::npos, "newName");
        }
        Info<< "after replace: " << test3 << endl;

        // do another replace
        // this uses the Foam::string::replace
        test3.replace("OpenFOAM", "openfoam");
     }
     */
    // Info<< "after replace: " << test3 << endl;
       
       
   /*
    string s;
    Sin.getLine(s);

    string s2(s.expand());

    cout<< "output string with " << s2.length() << " characters\n";
    cout<< "ostream<<  >" << s2 << "<\n";
    Info<< "Ostream<<  >" << s2 << "<\n";
    Info<< "hash:" << hex << string::hash()(s2) << endl;   
    Info<< "End\n" << endl;
    return 0;
    */
}


// ************************************************************************* //
