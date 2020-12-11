#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *sequence = NULL;
int num_tracks, sequence_size, algo;

void
swap (int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void
bubbleSort (int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)

    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
	swap (&arr[j], &arr[j + 1]);
}

void
option1 ()
{
  // prompt for number of concentric tracks, size of sequence, and scheduling algorithm
  printf ("Enter number of concentric tracks: ");
  scanf ("%d", &num_tracks);
  printf ("Enter size of sequence: ");
  scanf ("%d", &sequence_size);
  printf ("Enter scheduling algorithm (0=FIFO, 1=SSTF): ");
  scanf ("%d", &algo);

  if (sequence != NULL)
    free (sequence);

  sequence = (int *) malloc (sequence_size * sizeof (int));	// check this(malloc)
  return;
}


/*******************************************/
void
option2 ()
{
  int i, j;
  int temp;			// used fpr  swapping elements of array when sorting
  int traversed;
  int *sorted;
  int total_delay = 0;
  float average_delay = 0.0;
  int num_tracks_moved = 0;
  int longest_delay = 0;
  int longest_track = 0;
  int num_moves_right = 0;



  printf ("Enter sequence of tracks to seek: ");
  for (i = 0; i < sequence_size; i++)
    {
      scanf ("%d", &sequence[i]);
      if (sequence[i] < 0 || sequence[i] > num_tracks){
	  printf ("Out of range!");
	  return;
	  }	
    }

  // If FIFO
  if (algo == 0)
    {
      printf ("Traversed sequence: ");
      for (i = 0; i < sequence_size; i++)
	{	
	  printf ("%d ", sequence[i]);
	}

      traversed = sequence[0];
      
      for (i = 1; i < sequence_size; i++)
	{
	  traversed += abs (sequence[i] - sequence[i - 1]);
	}
	
	printf("\nThe number of tracks traversed is: %d\n", traversed);
          
    } 
  
  // Else SSTF
  else if (algo == 1){
      sorted = (int *) malloc (sequence_size * sizeof (int));
      
      for (i = 0; i < sequence_size; i++)
	{
	  sorted[i] = sequence[i];
	}
      
      bubbleSort (sorted, sequence_size);
      
      for (i = 0; i < sequence_size; i++)
	{
	  j = i + 1;
	  num_moves_right = 0;
	  
	  while ((j < sequence_size) && (sequence[i] != sorted[j]))
	    {
	      j++;
	    }
	    
	  if (j < sequence_size)
	    {
	      // calculate delays based on difference between track position in sorted array and original array
	      num_moves_right = j - i;
	      total_delay += num_moves_right;
	      num_tracks_moved++;
	      
	      // update value of longest delay if number of moved positions is greater than current longest delay              
	      if (num_moves_right > longest_delay){
    		  longest_delay = num_moves_right;
    		  longest_track = sequence[i];
		    }		
	    }		
	  
	}

      printf ("Traversed sequence: ");
      for (i = 0; i < sequence_size; i++)
      {
	        printf ("%d ", sorted[i]);
      }
      
      average_delay = total_delay / num_tracks_moved;
      printf ("\nThe average delay: %.1f\n", average_delay);
      printf ("The longest delay: %d by track: %d\n", longest_delay, longest_track);
      free (sorted);

    }

  return;
}


/***************************************************************/
void
option3 ()
{
  // if sequence is not NULL, free sequence
  return;
}				// 


/***************************************************************/
int
main ()
{
  int userSelection;
  do
    {
      printf ("\nDisk Scheduling\n");
      printf ("--------------------------------\n");
      printf ("1) Enter parameters\n");
      printf ("2) Schedule Disk Tracks\n");
      printf ("3) Quit program and free memory\n");

      printf ("\nEnter Selection: ");
      scanf ("%d", &userSelection);
      switch (userSelection)
	{
	case 1:
	  option1 ();
	  break;
	case 2:
	  option2 ();
	  break;
	case 3:
	  option3 ();
	  break;
	}

    }
  while (userSelection != 3);
  printf ("BYE BYE");
  return 0;
  return 1;
}

