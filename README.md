To run the code:

For running the first serialized parsing method test: 
- make bin/serialMain1
- bin/serialMain1.exe

For running the first parallel parsind method test:
- make bin/parallelMain1
- bin/parallel1Main.exe

To clean the program:
- make clean

# Parallel Thread Testing results

Measured in microseconds (average of 3 runs)

- 2 Threads: ~708509
- 4 Threads: ~550000
- 8 Threads: ~445000
- 12 Threads: ~432000
- 16 Threads: ~445000
