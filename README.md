# DEPRECATED
** This version of the eSTARlight package is no longer maintained. For the current version [visit](https://github.com/eic/estarlight/) **
# eSTARlight
eSTARlight is a Monte Carlo that simulates coherent vector meson photo- and electro-production in electro-ion collisions. It can produce a variety of final states at different center of mass energies for different collision systems at arbitrary values for the photon virtuality.

### Papers and presentations

 - [Exclusive vector meson production at an electron-ion collider](https://arxiv.org/abs/1803.06420): M. Lomnitz & S. Klein, Submitted to _Phys. Rev. C_ and currently under review arXiv:1803.06420
 - [Coherent vector meson production at an EIC](###): M. Lomnitz and S. Klein, Presented at the Workshop for Deep Inelastic Scattering, Kobe Japan, 2018.

## Authors

- [Michael Lomnitz](https://github.com/mlomnitz) (mrlomnitz@lbl.gov)[<sup>1</sup>]
- [Spencer Klein](https://github.com/SpencerKlein) (srklein@lbl.gov)[<sup>1</sup>]

[1]: Lawrence Berkeley National Laboratory, Relativistic Nuclear Collisions Program, Nuclear Science Division.

All rights rights reserved.

## Declaration

Portions of this package were originally inherited/based on the [STARlight](https://starlight.hepforge.org/) Monte Carlo generator. We would like to aknowledge the authors J. Nystrand, J. Seger and Y. Gorbunov for their contributions to STARLgiht.  This work was funded by the U.S. Department of Energy under contract number DE-AC-76SF00098.

## Instructions for use
The following instructions illustrate the procedure to install and run eSTARlight in a \*nix based environment:
 - Download the code package from [Hepforge](mia) or [Github](mia) and move to the desired location, i.e. ~/the_path/eSTARlight
 - Change to the installation directory of your choice
     - mkdir ~/my/installation/dir
     - cd ~/my/installation/dir
 - Set up the installation using cmake: 
     - cmake ~/the_path/eSTARlight/trunk
 - Compile the code using (g)make:
     - (g)make 
     - The compilation will produce two executables to run either STARlight or eSTARlight
 - Set up the desired running conditions in the input file:
     - cp ~/the_path/eSTARlight/slight.in .
     - vim slight.in
     - *Note:* As of yet, the positron/electron beam must be set to beam1, it is selected by setting:
         - BEAM_1_Z = +/- 1 (as of yet both positrons and electrons are modelled identically)
         - BEAM_1_A = 0
 - Run the simulation:
     - ./e_starlight > output.txt
     - output.txt will contain the program log and calculated cross-section for the simulation sample
     - The event catalogue will be emptied into the file slight.out
 - Interpret the result. We have provided a macro to convert the output into a [ROOT](https://root.cern.ch/) TTree:
     - root -b -q -l ~/the_path/eSTARlight/trunk/utils/ConvertStarlightAsciiToTree.C
     - TTree is output to starlight.root
 - Analyze your data:
     - We have included template [analysis](https://github.com/mlomnitz/eSTARlight/tree/master/analysis) (~/the_path/eSTARlight/analysis/) code that reads slight.root and fill histograms. For more details please look at the [README](https://github.com/mlomnitz/eSTARlight/blob/master/trunk/Readme.pdf)
     - cd ~/the_path/eSTARlight/analysis
     - sh e_run.sh ~/the_path/starlight.root

## Documentation
A more detailed version of the [README](https://github.com/mlomnitz/eSTARlight/blob/master/trunk/Readme.pdf) is included as part of the software package, located in:
 - ~/the_path/eSTARlight/trunk/Readme.pdf
 - ~/the_path/eSTARlight/trunk/Readme.docx

Finally, the full documentation with class description and dependencies is also available with the package download. To view the documentation:
     - Open the file ~/the_path/eSTARlight/trunk/doxygen/html/index.html

We have also included a config file to generate a fresh version of the documentation (for instance in the case of any updates). To following steps can be used to generate the documentation:
 - Download and install the [doxygen](https://www.stack.nl/~dimitri/doxygen/manual/install.html)
 - Move into the source code trunk:
     - cd ~/the_path/eSTARlight/trunk/
 - If necessary, delete previous documentation to avoid any conflicts:
     - rm ~/the_path/eSTARlight/trunk/doxygen/html/*
 - Generate the documentation:
     - doxygen estarlightDoxyfile.conf
 - The documentation should be generated and available in the previous location
