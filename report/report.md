# Report

## Cover Page
![Image](logo.png)<br>
<p style="text-align: center;">Vector Text-based Editor</p>
MEUNIER Antoine, ASSEPO Warren<br>
Promo 2027

## Introduction
After having created a Tetris-like game in Python during the first semester, we were now tasked to create from scratch a vector-image editor for a command line interface. <br>
This project helped us not only better our understanding of the C language, but also of lower-level programming than with Python, and a deeper understanding of algorithms.<br>
<br>
This vector-editor let the user draw in the terminal using different shapes.<br>

## A functional presentation of the completed project
- Name the functions realized among those proposed in the project.
- List the new proposed functions in addition to what was asked (if any).

## A technical presentation of the project
- Description of the main implemented algorithms
- Justification of the choice of data structures used.
- Presentation of the (technical) difficulties encountered and the solutions provided.

## Results presentation:
- Tests carried out and results obtained: present the user interface (illustrated by
screenshots)

## Notes / What differs from the subject
- In shapes.h, #pragma once includes the file only once at compilation.
- In area.c/h, renamed clear_area to initialize_area for clarity 

- We chose not to use a "Pixel" structure, as we deemed it unnecessary to print shapes to the area.
- Instead, we have a function that simply takes the shape and the area and computes the pixel to be enabled at the same time as they are drawn.
 
- For the line drawing algorithm, we chose to use DDA, as it is a simpler algorithm to implement, and it works well enough.

- For the square drawing algorithm, the top and bottom line can be optimized by 4 pixels. flm

- changed read_exec_command to exec_command for clarity
