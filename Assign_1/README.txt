Name: Andres Imperial
Email: andres.imperial@csu.fullerton.edu


How to execute:
	Simply compile given source code (*.cpp) with the g++ compiler and if
	desired specify an output file, else default file should be a.out. 
	Format follows:g++ <file_name>.cpp -o <output_file_name>


Execution times for downloaders:
andres@andres-desktop:~/Fall_2016/CS_351/Assign_1$ time ./serial_downloader 

real	12m18.994s
user	0m4.344s
sys	0m24.916s

andres@andres-desktop:~/Fall_2016/CS_351/Assign_1$ time ./parallel_downloader 

real	6m19.686s
user	0m3.640s
sys	0m21.020s

1. In the output of time, what is the diffence between real, user, and sys times?

2. Which is longer: user time or sys time?  Use your knoweldge to explain why.

3. When downloading the files above, which downloader finishes faster?  Why do you think
that is?

4. Repeat the experiment for 10 files (any reasonably large-sized files, e.g., 100 MB, will do).
Is the downloader in the previous question still faster?  If not so, why do you think that
is?

