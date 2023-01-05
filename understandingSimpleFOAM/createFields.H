//U vector
// P 
// nu 
// Pold 


Info << nl << "Reading pressure field" << endl;
volScalarField p
(
 	IOobject
	(
	 	"p",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);


Info << nl << "Reading Velocity field" << endl;
volVectorField U
(
 	IOobject
	(
	 	"U",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);

surfaceScalarField phi  // U vector interpolation to the mesh surface vector . U.mesh.Sf()
(
 	IOobject
	(
	 	"phi",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::NO_WRITE
	),
	fvc::interpolate(U) & mesh.Sf()
);



Info << nl << "Reading pressure old" << endl;
volScalarField pold
(
 	IOobject
	(
	 	"pold",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::NO_WRITE
	),
	p
);


IOdictionary transportProperties
(
 	IOobject
	(
		"transportProperties",
		runTime.constant(),
		mesh,
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


IOdictionary fvSolution
(
 	IOobject
	(
		"fvSolution",
		runTime.system(),
		mesh,
		IOobject::MUST_READ_IF_MODIFIED,
		IOobject::NO_WRITE
	)
);


scalar alpha;
fvSolution.lookup("alpha")>>alpha;


scalar pRefCell;
fvSolution.lookup("pRefCell")>>pRefCell;


scalar pRefValue;
fvSolution.lookup("pRefValue")>>pRefValue;






