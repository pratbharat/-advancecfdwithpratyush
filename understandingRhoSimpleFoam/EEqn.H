{
    volScalarField& he = thermo.he();

  Info<< "he.name(): "<< he.name()<<endl;
/*
   he.name() == "e"
          ? Info<<"Print Internal Energy "
          : Info<<"Print Enthalpy" ;
*/
    fvScalarMatrix EEqn
    (
        fvm::div(phi, he)
      + (
            he.name() == "e"
          ? fvc::div(phi, volScalarField("Ekp", 0.5*magSqr(U) + p/rho))
          : fvc::div(phi, volScalarField("K", 0.5*magSqr(U)))
        )
      - fvm::laplacian(turbulence->alphaEff(), he)
    );

    EEqn.relax();

    EEqn.solve();

    thermo.correct();   // It will correct all the thermophysical properties 

}

