// Include the global PaGMO header.
#include <pagmo.h>
//#include <algorithm/gsl_nm2rand.h>
#include <iostream>
using namespace std;
using namespace pagmo;
int main()
{
        // Initialise the MPI environment.
        mpi_environment env;
        // Create a problem and an algorithm.
        problem::dejong prob(10);
        algorithm::monte_carlo algo(100);
        algorithm::de central;
        // Create an archipelago of 10 MPI islands.
        archipelago a;
        a.set_topology(topology::ring());
        a.push_back(mpi_island(central,prob,50));
        for (int i = 1; i < 10; ++i) {
                a.push_back(mpi_island(algo,prob,10));
        }
        // Evolve the archipelago 10 times.
        a.evolve(10);
        a.join();
        for(int i=0;i<10;i++)
            cout<<a.get_island(i)->get_population().champion().human_readable()<<endl;
        return 0;
}