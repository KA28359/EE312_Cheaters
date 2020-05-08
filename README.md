# EE312_Cheaters

Cheaters:

This is a plagiarism detection software that will take in a set of files and return the similarity values between two files in the given set. The higher the output value is, the higher chance there was for plagiarism. The program utilizes linked list, 2-D arrays, hash tables, and many other c++ techniques. The program isn't 100% accurate as some of the collisions may have occurred because of similar hash values from the hash function even though they are not necessarily the same string. In an attempt to minimize this, I used a polynomial rolling hash function. Some files may have also mapped to the same hash value multiple times but it was only counted as once for simplicity sake. The program output is still an accurate representation of a plagiarism detection software. 


How to use:

You should have all the files from the zip folder and a folder with documents that will be searched in the same directory. After that open a terminal and go to the directory containing all of the files. Type 'make' into the terminal at the directory in order to create the executable. Once created you can run the program as shown below.

./plagiarismChecker /path/to/folder/ chunk_val threshold_for_number_of_similarities

EX: ./plagiarismChecker /home/ecelrc/students/kaguilar/Cheaters/sm_doc_set/ 6 200

The output will look like the following:

1623: sra31.txt jrf1109.txt
675: edo26.txt abf0704.txt
530: abf0704.txt abf70402.txt
423: bef1121.txt edo14.txt
384: tyc12.txt catchmeifyoucan.txt
311: hal10.txt catchmeifyoucan.txt
285: ecu201.txt catchmeifyoucan.txt

The values on the left show the number of similar chunks found between the two text files on the right. 
