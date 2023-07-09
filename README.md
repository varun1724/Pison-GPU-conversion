# Running Code

For running the first serialized parsing method test: 
- make bin/serialMain1
- bin/serialMain1.exe

For running the first parallel parsind method test:
- make bin/parallelMain1
- bin/parallel1Main.exe

To clean the program:
- make clean

# Google Colab Instructions
- Select the block of code directly below the "Running serial test code" text
- At the top left, select "runtime" then "run before"
- Run the blocks for desired tests (may have to change path of the dataset to your local path in your drive)

#Link to datasets
- [datasets](https://drive.google.com/drive/folders/1KQ1DjvIWpHikOg1JgmjlSWM3aAlvq-h7)

# Parallel Thread Testing results

Measured in microseconds (average of 3 runs)

- 2 Threads: ~708509
- 4 Threads: ~550000
- 8 Threads: ~445000
- 12 Threads: ~432000
- 16 Threads: ~445000

# Credits
- Code expanded from [AutomataLab](https://github.com/AutomataLab/Pison)
