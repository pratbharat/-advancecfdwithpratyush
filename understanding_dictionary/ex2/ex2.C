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
    ex2

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "dictionary.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

using namespace Foam;

int main(int argc, char *argv[])
{
	
	//Constructor 
	 //dictionary(const fileName& name);
      dictionary dict1("file1");
      
      Info<<"first constructor: "<<dict1<<endl;

        //- Add a string entry
       //  optionally overwrite an existing entry
      //void add(const keyType&, const string&, bool overwrite=false);
   
      dict1.add("myValue", "zero", true); 
      Info<<"After adding a string: "<<dict1<<endl;
      
      /*
      //- Construct given the entry name, parent dictionary and Istream,
         //  reading entries until lastEntry or EOF
         dictionary
         (
             const fileName& name,
             const dictionary& parentDict,
             Istream&
         );
         */ 
         //Istream is an abstract class.
         //1. You cantn't create abstract class.
         //2. You can either create a pointer or refrecne. 
         //3. There will be atleast one method whose value will be =0  (virtual funct=0).
         //4. This is used to tell that how  the subclasses should be defined. 
         
         Istream& is = dict1.lookup("myValue");
         
          dictionary dict2
         (
             "file2",
             dict1,
             is
         );
         
         Info<<"Second constructor: "<<dict2<<endl;
         
         //- Construct top-level dictionary from Istream,
         //  reading entries until EOF
         // dictionary(Istream&);
         
         dictionary dict3(is);
         
         Info<<"Third constructor: "<<dict3<<endl;
         
         
         //- Construct as copy given the parent dictionary
        // dictionary(const dictionary& parentDict, const dictionary&);
     
         dictionary dict4(dict1, dict1);
         
         Info<<"Fourth constructor: "<<dict4<<endl;
         
         dictionary dict5(dict2);
         
          
         Info<<"Fifth constructor: "<<dict5<<endl;
         
         //Member Functions
         
            //  optionally overwrite an existing entry
            // void add(const keyType&, const word&, bool overwrite=false);
         word myname = "Pratyush";
         dict2.add("myValue2",myname, true);
         
         Info<<"dict2 modification first: "<<dict2<<endl;
            
                //  optionally overwrite an existing entry
             //void add(const keyType&, const label, bool overwrite=false);
             
             
         label val = 123;
         dict2.add("myValue3",val, true);
         
         Info<<"dict2 modification second: "<<dict2<<endl;
 
             //- Add a scalar entry
             //  optionally overwrite an existing entry
           //  void add(const keyType&, const scalar, bool overwrite=false);
           
         scalar val2 =0.000001;
         dict2.add("myValue3",val2, true);
         
         Info<<"dict2 modification Third: "<<dict2<<endl;
           
           
           //- Add a dictionary entry
             //  optionally merge with an existing sub-dictionary
             /*
             void add
             (
                 const keyType&,
                 const dictionary&,
                 bool mergeEntry=false
             );  */
             
             
         dict2.add("myValue4",dict1, true);
         
         Info<<"dict2 modification fourt: "<<dict2<<endl;
             
             /*
               //- Add a T entry
             //  optionally overwrite an existing entry
             template<class T>
             void add(const keyType&, const T&, bool overwrite=false);
             */ 
         vector v1(0,0.1,0.2);
         dict2.add<vector>("myValue5",v1, true);
         
         Info<<"dict2 modification fifth: "<<dict2<<endl;
             
             
         //- Assign a dictionary entry, overwrite any existing entry
          //void set(const keyType&, const dictionary&);
    
          dict2.set("myValue2", dict1);
          
          Info<<"dict2 modification set: "<<dict2<<endl;
          
          //bool remove(const word&);
          
          dict2.remove("myValue2");
          
          
          Info<<"dict2 modification remove: "<<dict2<<endl;
          
          
          //- Clear the dictionary
          //   void clear();
          
          
           // dict2.clear();
          
          //Info<<"dict2 modification clear: "<<dict2<<endl;
          
          //Operators 
          //<< : Output Operators
          //+ 
           dict3= dict1+dict2;
           
           Info<<"+ Operator: "<<dict3<<endl;
                  
            //lookup
            /*
             //- Find and return an entry data stream if present otherwise error.
             //  If recursive, search parent dictionaries.
             //  If patternMatch, use regular expressions.
             const entry& lookupEntry
             (
                 const word&,
                 bool recursive,
                 bool patternMatch
             ) const;
             */
             
            Info<<"lookup1: "<<dict2.lookupEntry("myValue5",true,true)<<endl;
                  
              /*    
               //- Find and return a T, if not found return the given
             //  default value, and add to dictionary.
             //  If recursive, search parent dictionaries.
             //  If patternMatch, use regular expressions.
             template<class T>
             T lookupOrAddDefault
             (
                 const word&,
                 const T&,
                 bool recursive=false,
                 bool patternMatch=true
             );
             * */
             vector v2(0,0.4,0.9);
             dict2.lookupOrAddDefault<vector>(
               "myValue6",
               v2   
             );
             Info<<" lookupOrAddDefault: "<<dict2<<endl;
     
             
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    return 0;
}


// ************************************************************************* //
