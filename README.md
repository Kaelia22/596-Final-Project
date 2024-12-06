## CSCI Final Project: Visualizing Thermal Equilibrium

### Project Objective
Our project leverages VMD visualization software to simulate thermal equilibrium through a dynamic, color-coded representation of molecules. Molecules are color-coded based on their kinetic energy, with higher temperatures corresponding to warmer colors and lower temperatures to cooler ones. By placing molecules with significantly different temperatures in the same simulation box, the system visually demonstrates how they exchange energy and gradually reach thermal equilibrium. This approach allows us to intuitively observe temperature changes in real-time, making the process of energy flow and distribution both accessible and engaging.

### Motivation
1. help visualize abstract thermodynamic principles in a way that’s intuitive and memorable. Concepts like thermal equilibrium can often feel theoretical, but our project brings them to life.
2. visualizations make scientific learning engaging and accessible.

<div align="center">
  <img src="images/equilibrium.png" alt="Example Image" width="300">
</div>

---
### Challenges
1. Were able to simulate thermal equilibrium through movement of atoms in a box but unable to add colors using xyz file
2. Pivoted to pmd file and figured out which coloring method to use to get colors to show up but realized kinetic energy values weren't being properly read
3. Figured out that VMD is very sensitive to spacing in pmd files and therefore it wasn't reading the correct values
4. Able to fix spacing through trail and error but now we realized that our script wasn't correctly simulating the change in kinetic energy- only the change in atom position

---
### Expected Results

---
### References
