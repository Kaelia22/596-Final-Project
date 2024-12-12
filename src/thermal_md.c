#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100           // Number of atoms
#define BOX_SIZE 10.0   // Size of the MD box
#define TIMESTEPS 1000  // Number of frames
#define MASS 1.0        // Mass of atoms
#define DT 0.01         // Time step

typedef struct {
    double x, y, z;    // Position
    double vx, vy, vz; // Velocity
    double ke;         // Kinetic energy
} Atom;

void initialize_atoms(Atom *atoms) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        // Initialize positions randomly in the box
        atoms[i].x = ((double)rand() / RAND_MAX) * BOX_SIZE;
        atoms[i].y = ((double)rand() / RAND_MAX) * BOX_SIZE;
        atoms[i].z = ((double)rand() / RAND_MAX) * BOX_SIZE;

        // Initialize velocities: Half box high temperature, half low temperature
        if (atoms[i].x < BOX_SIZE / 2) {
            // High temperature region
            atoms[i].vx = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            atoms[i].vy = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            atoms[i].vz = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        } else {
            // Low temperature region
            atoms[i].vx = ((double)rand() / RAND_MAX) * 0.5 - 0.25;
            atoms[i].vy = ((double)rand() / RAND_MAX) * 0.5 - 0.25;
            atoms[i].vz = ((double)rand() / RAND_MAX) * 0.5 - 0.25;
        }

        // Calculate initial kinetic energy
        atoms[i].ke = 0.5 * MASS * (atoms[i].vx * atoms[i].vx +
                                    atoms[i].vy * atoms[i].vy +
                                    atoms[i].vz * atoms[i].vz);
    }
}

void update_atoms(Atom *atoms) {
    for (int i = 0; i < N; i++) {
        // Update positions based on velocity
        atoms[i].x += atoms[i].vx * DT;
        atoms[i].y += atoms[i].vy * DT;
        atoms[i].z += atoms[i].vz * DT;

        // Apply periodic boundary conditions using modulo
        atoms[i].x = fmod(atoms[i].x + BOX_SIZE, BOX_SIZE);
        atoms[i].y = fmod(atoms[i].y + BOX_SIZE, BOX_SIZE);
        atoms[i].z = fmod(atoms[i].z + BOX_SIZE, BOX_SIZE);

        // Update kinetic energy
        atoms[i].ke = 0.5 * MASS * (atoms[i].vx * atoms[i].vx +
                                    atoms[i].vy * atoms[i].vy +
                                    atoms[i].vz * atoms[i].vz);
    }
}

void write_pdb(FILE *file, Atom *atoms, int timestep) {
    fprintf(file, "MODEL     %d\n", timestep);  // Model number for each timestep

    for (int i = 0; i < N; i++) {
        // Kinetic energy-based B-factor (color coding)
        double b_factor = atoms[i].ke;
        // if (b_factor > 1.0) b_factor = 1.0;
        // if (b_factor < 0.0) b_factor = 0.0;


        // Floor or Ceil the b_factor to make it 0 or 1
        // b_factor = (b_factor >= 50) ? 1.0 : 0.0; // If above 50, set to 1; otherwise, set to 0

        // PDB format: ATOM   serial  atom  resname  chain  resseq  x   y   z   bfactor
        fprintf(file, "ATOM  %5d  C   UNK A%4d    %8.3f%8.3f%8.3f  1.00%6.2f\n", 
                i + 1, i + 1, atoms[i].x, atoms[i].y, atoms[i].z, b_factor);
    }
    fprintf(file, "ENDMDL\n");
}

int main() {
    Atom atoms[N];
    initialize_atoms(atoms);

    FILE *pdb_file = fopen("output.pdb", "w");
    if (!pdb_file) {
        perror("Error creating PDB file");
        return 1;
    }

    for (int t = 0; t < TIMESTEPS; t++) {
        write_pdb(pdb_file, atoms, t);
        update_atoms(atoms);
    }

    fclose(pdb_file);

    printf("PDB file created successfully: output.pdb\n");
    return 0;
}
