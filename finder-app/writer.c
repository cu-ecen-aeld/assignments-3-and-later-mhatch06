#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

	// Open Syslog
	openlog("writer", LOG_PID, LOG_USER);

	// Check for correct num of args	
	if (argc != 3) {
		syslog(LOG_ERR, "Invalid # of Args");
		printf("Error: Invalid # of Args");
		closelog();
		return 1;
	}

	const char *writefile = argv[1];
	const char *writestr = argv[2];

	    // Open the file for writing
 	FILE *file = fopen(writefile, "w");
    	if (file == NULL) {
        syslog(LOG_ERR, "Failed to open file %s for writing", writefile);
        printf("Error: Failed to open file %s for writing.\n", writefile);
        closelog();
        return 1;
    	}	

    	// Write the string to the file
    	if (fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Failed to write to file %s", writefile);
        printf("Error: Failed to write to file %s.\n", writefile);
        fclose(file);
        closelog();
        return 1;
    	}

    	// Log success message
    	syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    	// Close the file
    	fclose(file);

    	// Close syslog
    	closelog();

    	return 0;
}
