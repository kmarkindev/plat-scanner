# plat-scanner
Handy tool that scans dropped prime parts when closing a relic and shows their cost from warframe.market, 
helping you to make a better choice. Currently, the only supported language is Russian, because there is no working
analogue.

# Building
This project is using **Conan** as a package manager.
In order to be able to install all packages using it, you have to add the following remotes:
- https://center.conan.io (Default conan remote)
- https://bincrafters.jfrog.io/artifactory/api/conan/conan (Bincrafters remote)

After that, you are ready to build plat-scanner following these steps:

- Create build folder inside root folder of the project.
- Go to this folder.
- Run <code>conan install ..</code> or <code>conan install .. --build=missing</code> if there are MissingBinary errors.
- Run cmake configuration using <code>cmake ..</code>
- Finally, build everything in one piece by running <code>cmake --build .</code>

*PS: make sure you are building plat-scanner using same CMAKE_BUILD_TYPE as you
are using for conan packages. Otherwise, you will have link errors. You can config it by 
creating new conan profile.*

*PPS: Recommended settings are Visual Studio 17 x86_64*