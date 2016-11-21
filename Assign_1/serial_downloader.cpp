// Name: Andres Imperial
// Class: 351 TR 2:30pm
// Assignment 1 shell
// File: serial_downloader.cpp

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
using namespace std;

/**
 * Forks children and lets them perform their tasks
 * @param urls - the urls to download
 */
void create_children(vector<string>& urls)
{	
	/* The process id */
	pid_t pid;
	
	/* Go through all the URLs */
	for(vector<string>::iterator urlIt = urls.begin();
			urlIt != urls.end(); ++urlIt)
	{
		/* Create a child */
		pid = fork();


		/* Make sure the fork was a success */
		if(pid < 0)
		{
			perror("fork:");
			exit(1);
		}
		/* The child code */
		if(pid == 0)
		{	
			
			fclose(stdout);
			fclose(stderr);
			
			/* Deploy wget */
			if(execlp("/usr/bin/wget", "child", urlIt->c_str(), NULL) < 0)
			{
				perror("execlp");
				exit(1);
			}
				
		}
		
		// Parent's code
		if(pid > 0)
		{
			wait(NULL);
		}
	}	
}

/**
 * Read the URLs from the file
 * @param urls - the URLs to download
 */

void readUrls(vector<string>& urls)
{
	/* Open the file */
	ifstream urlFile("urls.txt");		
	
	/* The URL buffer */
	string urlBuffer;
	
	/* Make sure the file was opened */
	if(!urlFile.is_open())
	{
		fprintf(stderr, "Failed to open the file\n");
		exit(1);
	}
	
	/* Read the entire file */
	while(!urlFile.eof())
	{
		/* Read the buffer */
		urlFile >> urlBuffer;
		
		/* Are we at the end of the file */
		if(!urlFile.eof())
			urls.push_back(urlBuffer);	
	}
	
	/* Close the file */
	urlFile.close();
}

int main()
{
	
		
	/* Read the URL files */
	vector<string> urls;
		
	/* Read the URLs */
	readUrls(urls);
	
	/* Create child processes */
	create_children(urls);
	
	return 0;	
	
}
