# Tricks on Matrix
## Rotating a matrix
All rotations are composite reflections (in fact, all transformations are composite reflections); in case of ***Clockwise rotation(90 degrees)***, a reflection across the horizontal line of symmetry, then a reflection across the diagonal. 

If you recall this fact, this method will allow you to swap in-place rather than having to endure the tedium of multiplying by a rotation matrix.

### Clockwise rotation(90 degrees)
- reverse up and down i.e. reflection across the horizontal line of symmetry.
- swap symmetry i.e. transpose or a reflection across the diagonal.

1 2 3&ensp;&ensp;&ensp;&ensp;7 8 9&ensp;&ensp;&ensp;&ensp;7 4 1\
4 5 6&ensp;&ensp;&ensp;&ensp;4 5 6&ensp;&ensp;&ensp;&ensp;8 5 2\
7 8 9&ensp;&ensp;&ensp;&ensp;1 2 3&ensp;&ensp;&ensp;&ensp;9 6 3 

### Anti-Clockwise rotation(90 degrees)
- reverse left and right i.e. reflection across the vertical line of symmetry.
- swap symmetry i.e. transpose or a reflection across the diagonal.

1 2 3&ensp;&ensp;&ensp;&ensp;3 2 1&ensp;&ensp;&ensp;&ensp;3 6 9\
4 5 6&ensp;&ensp;&ensp;&ensp;6 5 4&ensp;&ensp;&ensp;&ensp;2 5 8\
7 8 9&ensp;&ensp;&ensp;&ensp;9 8 7&ensp;&ensp;&ensp;&ensp;1 4 7