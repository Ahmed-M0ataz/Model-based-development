# MATLAB and Model-Based Design (MBD) Lab 1

## Introduction

Welcome to Lab 1 of the MATLAB and Model-Based Design course. In this lab, we will explore various matrix operations using MATLAB.


```matlab
% Part 1: Calculate the sum of matrixA and matrixB
matrixA = [3 2 1; 6 5 4; 9 8 7];
matrixB = [12 11 10; 15 14 13 ; 18 17 16];
%  sum of matrixA and matrixB 
matrixSum = matrixA + matrixB

% Part 2: Concatenate rowVector and columnVector horizontally
rowVector = 1:5;
columnVector = (6:10)';

% Part 3: Use repmat function to replicate originalMatrix
originalMatrix = [1 2; 3 4];
repeatedMatrix = repmat(originalMatrix,2)

% Part 4: Perform matrix multiplication between identityMatrix and matrixA
identityMatrix = eye(3,3);

matrixProduct = identityMatrix * matrixA