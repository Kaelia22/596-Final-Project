## CSCI Final Project: Visualizing Thermal Equilibrium

### Project Objective
Our project aims to utilize VMD to visualize thermal equilibrium in molecular dynamics simulations by color-coding atoms based on their kinetic energy. The system provides a dynamic enviornment to observe the process of temperature equilibration after initially assigning distinct high temperatures to one side of a MD simulation box and low temperatures to the other side. The color-coded represenation allows users to intuitively track the distrubution and flow of energy across the system over time. Our approach facilitates a deeper understanding of thermal equilibrium while simultaneously providing a visually engaging method for analyzing energy exchanges in MD simulations.

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
