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

\*---------------------------------------------------------------------------*/

#include "myVelocityFvPatchVectorField.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"




// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::myVelocityFvPatchVectorField::
myVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(p, iF),
    Umax_(0.0),
    y_(1,0,0),
    n_(0,1,0)
{
}


Foam::myVelocityFvPatchVectorField::
myVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchVectorField(p, iF),
    Umax_(readScalar(dict.lookup("Umax"))),
    y_(pTraits<vector>(dict.lookup("y"))),
    n_(pTraits<vector>(dict.lookup("normal")))
{


    fixedValueFvPatchVectorField::evaluate();

    /*
    // Initialise with the value entry if evaluation is not possible
    fvPatchVectorField::operator=
    (
        vectorField("value", dict, p.size())
    );
    */
}


Foam::myVelocityFvPatchVectorField::
myVelocityFvPatchVectorField
(
    const myVelocityFvPatchVectorField& ptf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchVectorField(ptf, p, iF, mapper),
    Umax_(ptf.Umax_),
    y_(ptf.y_),
    n_(ptf.n_)
{}


Foam::myVelocityFvPatchVectorField::
myVelocityFvPatchVectorField
(
    const myVelocityFvPatchVectorField& ptf
)
:
    fixedValueFvPatchVectorField(ptf),
    Umax_(ptf.Umax_),
    y_(ptf.y_),
    n_(ptf.n_)
{}


Foam::myVelocityFvPatchVectorField::
myVelocityFvPatchVectorField
(
    const myVelocityFvPatchVectorField& ptf,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(ptf, iF),
    Umax_(ptf.Umax_),
    y_(ptf.y_),
    n_(ptf.n_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::myVelocityFvPatchVectorField::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchVectorField::autoMap(m);
}


void Foam::myVelocityFvPatchVectorField::rmap
(
    const fvPatchVectorField& ptf,
    const labelList& addr
)
{
    fixedValueFvPatchVectorField::rmap(ptf, addr);

    const myVelocityFvPatchVectorField& tiptf =
        refCast<const myVelocityFvPatchVectorField>(ptf);

}


void Foam::myVelocityFvPatchVectorField::updateCoeffs()
{
    if (updated())
    {
        return;
    }

     // 𝑼= 𝑼_𝒎𝒂𝒙 (𝟏−(𝒚−𝒄)^𝟐/𝒓^𝟐 )
       //U_max = userDefined 
       //Bounding range => patch=> faces =>localPoints=> min, max 
        
         boundBox BB (patch().patch().localPoints(),true);
          
         vector midCord =  0.5* (BB.max()+BB.min());
         
         vectorField yc = patch().Cf() - midCord;
         
         //y_ 
         scalarField temp1 = (2*(yc & y_ ))/ ((BB.max() - BB.min()) & y_); //(y-c/r)
         
         fixedValueFvPatchVectorField::operator==(
              Umax_ * n_ * (1 - sqr(temp1))
         );       
    
    fixedValueFvPatchVectorField::updateCoeffs();
}


void Foam::myVelocityFvPatchVectorField::write
(
    Ostream& os
) const
{
    fvPatchVectorField::write(os);
    os.writeKeyword("Umax") << Umax_<< token::END_STATEMENT << nl;
    os.writeKeyword("y") << y_ << token::END_STATEMENT << nl;
    os.writeKeyword("normal") << n_ << token::END_STATEMENT << nl;
}


// * * * * * * * * * * * * * * Build Macro Function  * * * * * * * * * * * * //

namespace Foam
{
    makePatchTypeField
    (
        fvPatchVectorField,
        myVelocityFvPatchVectorField
    );
}

// ************************************************************************* //
