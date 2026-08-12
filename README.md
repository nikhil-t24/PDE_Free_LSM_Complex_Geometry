<h2>PDE-free Level Set Method: On Lagrangian Advection and Geometric Reinitialization of the Interface in a Complex Geometry.</h2>

This repository contains the codes for PDE-free LSM solver with novel Geometric Reiniialization and Lagrangian Advection on a Curvilinear Structured Grid.

<h2>Software requirements</h2>
This solver needs:   gcc (compiler for C++ code) 

<h2>How to install the gcc packages (on a Linux system)</h2>
sudo apt install build-essential

<h2>How to compile and run the code</h2>


To compile the code: g++ -o output -mcmodel=large Main.cpp -O3

To run this code: ./output


<h1>Fully FVM and ALE-based FfSI Solver with a Novel Hybrid Grid</h1>

<p>
This repository contains the codes for Arbitrary Lagrangian Eulerian (ALE)-based
in-house Fluid flexible-Structure Interaction (FfSI) solver with Novel Hybrid
AMM-MRR-SEMM Grid Generation Methodology on a Curvilinear Structured Grid with
Fully FVM-based discretisation.
</p>

<h2>Software requirements</h2>

<p>This solver needs:</p>

<ul>
  <li>gcc</li>
  <li>mpi (for parallel implementation)</li>
</ul>

<h2>How to install the required packages (on a Linux system)</h2>

<p>To install gcc (compiler for C code)</p>

<pre><code>sudo apt install build-essential</code></pre>

<p>To install mpi (OpenMPI)</p>

<pre><code>sudo apt install mpich</code></pre>

<h2>How to compile and run the code</h2>

<p>To compile the code</p>

<pre><code>./compile.sh</code></pre>

<p>To run this code</p>

<pre><code>./output</code></pre>




