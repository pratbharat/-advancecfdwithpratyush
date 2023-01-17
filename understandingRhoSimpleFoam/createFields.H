
//First Add the thermophysical model 

Info<< "Reading thermophysical properties\n" << endl;

autoPtr<fluidThermo> pThermo
(
    fluidThermo::New(mesh)
);
fluidThermo& thermo = pThermo();


thermo.validate(args.executable(), "h", "e");

//U vector
// P 
// nu 
// Pold 


volScalarField& p = thermo.p();

volScalarField rho
(
    IOobject
    (
        "rho",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    thermo.rho()
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
	linearInterpolate(rho*U) & mesh.Sf()
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


pressureControl pressureControl(p, rho, simple.dict());


Info<< "Creating turbulence model\n" << endl;
autoPtr<compressible::turbulenceModel> turbulence
(
    compressible::turbulenceModel::New
    (
        rho,
        U,
        phi,
        thermo
    )
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

const volScalarField& psi = thermo.psi();




