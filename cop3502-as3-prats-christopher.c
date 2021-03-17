// all-monster-sorts.c - Sort monsters by name and weight.

/* The idea of sorting is simple: take unordered objects, and arrange them in an
   order.  It has a lot of uses, so there's been a lot of work done with it.  Here,
   we're going to demonstrate a few of the simpler, more classic sorting techniques.
   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <time.h>

/* Monster structure and helper functions - DO NOT MODIFY THESE. */

typedef struct monster {
	int id;
	char name[64];
	char element[64];
	int population;
	double weight;
} monster;

monster *make_some_monsters(int n)
{
  monster *monsters = malloc(sizeof(monster) * n);

  time_t t;

  srand((unsigned) time(&t));

  for(int i = 0; i < n; i++)
  {
    monsters[i].id = i;
    sprintf(monsters[i].name, "Monster #%d", rand());
    sprintf(monsters[i].element, "Element #%d", rand());
    monsters[i].population = rand();
    monsters[i].weight = 500.0 * ((double) rand() / (double) RAND_MAX);
  }

  return monsters;
}

void output_monster_list(monster *list, int n, char *title) {
  printf("List %s:\n", title);
  for(int i = 0; i < n; i++) {
    printf("  Monster %d: %s %s %d %lf\n", i, list[i].name, list[i].element, list[i].population, list[i].weight);
  }
  printf("\n");
}

void print_clocks(clock_t clocks) {
  printf("  %lfs CPU time used\n", ((double) clocks) / CLOCKS_PER_SEC);
}

void swap_monsters(monster *list, int i, int j)
{
  monster temp;

  memcpy(&temp, list + i, sizeof(monster));
  memcpy(list + i, list + j, sizeof(monster));
  memcpy(list + j, &temp, sizeof(monster));
}

int compare_monsters(monster *m1, monster *m2, int use_name, int use_weight);

void check_monster_sort(monster *list, int n, int use_name, int use_weight)
{
  for(int i = 1; i < n; i++) {
    if(compare_monsters(list + i - 1, list + i, use_name, use_weight) > 0) {
      printf("*** The list is NOT sorted.\n\n");
      return;
    }
  }
  printf("The list is sorted.\n\n");
}

/* The core comparison function. */

int compare_monsters(monster *m1, monster *m2, int use_name, int use_weight)
{
	//Compare Name
	if (use_name) {
		if (strcmp(m1->name, m2->name) >= 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	//Compare Weight
	else {
		if (m1->weight >= m2->weight) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

/* Implement ascending quick sort. */

int repartition(monster *list, int low_index, int high_index, int *comparisons, int *swaps,
		int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Recursive function for quick sort. */

void quick_sort_recursive(monster *list, int low_index, int high_index, int *comparisons, int *swaps,
		int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Shell function for quick sort. */

void quick_sort(monster *list, int n, int use_name, int use_weight)
{
	int comparisons = 0;
	int swaps = 0;
	clock_t start_cpu, end_cpu;

	printf("Quick sort %d monsters by %s...\n", n, use_name ? "name" : "weight");

	start_cpu = clock();
	quick_sort_recursive(list, 0, n-1, &comparisons, &swaps, use_name, use_weight);
	end_cpu = clock();

	printf("Sort complete with %d comparisons and %d swaps.\n", comparisons, swaps);
	print_clocks(end_cpu - start_cpu);
}

/* Implement ascending bubble sort. */

void bubble_sort(monster *list, int n, int use_name, int use_weight) 
{
	int i;
	int j;
	int temp;
	int comparisons = 0;
	int swaps = 0;
	clock_t start_cpu, end_cpu;

	printf("Bubble sort %d monsters by %s...\n", n, use_name ? "name" : "weight");

	start_cpu = clock();

	// YOUR CODE GOES HERE.

	end_cpu = clock();
	printf("Sort complete with %d comparisons and %d swaps.\n", comparisons, swaps);
	print_clocks(end_cpu - start_cpu);
}

/* Highest-value finder for selection sort. */

int find_highest(monster *list, int n, int *comparisons, int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Implement ascending selection sort. */

void selection_sort(monster *list, int n, int use_name, int use_weight)
{
	int i;
	int highest;
	int comparisons = 0;
	int swaps = 0;
	clock_t start_cpu, end_cpu;

	printf("Selection sort %d monsters by %s...\n", n, use_name ? "name" : "weight");
	start_cpu = clock();

	// YOUR CODE GOES HERE.

	end_cpu = clock();
	printf("Sort complete with %d comparisons and %d swaps.\n", comparisons, swaps);
	print_clocks(end_cpu - start_cpu);
}

/* Find position for insertion sort. */

int insertion_sort_find_position(monster *list, int low_index, int high_index, monster *k, int *comparisons, int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Implement insertion sort. */

void insertion_sort_internal(monster *list, int n, int *comparisons, int *copies, int *block_copies, int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Shell for insertion sort. */

void insertion_sort(monster *list, int n, int use_name, int use_weight)
{
	int comparisons = 0;
	int block_copies = 0;
	int total_copies = 0;
	clock_t start_cpu, end_cpu;
	printf("Insertion sort %d monsters by %s...\n", n, use_name ? "name" : "weight");
	start_cpu = clock();

	insertion_sort_internal(list, n, &comparisons, &total_copies, &block_copies, use_name, use_weight);

	end_cpu = clock();
	printf("Sort complete with %d comparisons and %d block copies (%d total copies).\n", comparisons, block_copies, total_copies);
	print_clocks(end_cpu - start_cpu);
	return;
}

/* Merge function for merge sort.  Merges sub-arrays [l1..h1] and [l2..h2].
   Must have l2 = l1 + 1 or bad things will happen. */

void merge_sort_merge(monster *list, int l1, int h1, int l2, int h2, 
		int *comparisons, int *copies, int *block_copies, int *mallocs,
		int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Recursive function for merge sort. */

void merge_sort_recursive(monster *list, int low_index, int high_index, 
		int *comparisons, int *copies, int *block_copies, int *mallocs,
		int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Implement merge sort. */

void merge_sort(monster *list, int n, int use_name, int use_weight)
{
	int comparisons = 0;
	int copies = 0;
	int block_copies = 0;
	int mallocs = 0;
	clock_t start_cpu, end_cpu;

	printf("Merge sort %d monsters...\n", n);

	start_cpu = clock();
	merge_sort_recursive(list, 0, n-1, &comparisons, &copies, &block_copies, &mallocs,
			use_name, use_weight);
	end_cpu = clock();

	printf("Sort complete with %d comparisons, %d block copies, %d total copies, %d mallocs.\n", comparisons, block_copies, copies, mallocs);
	print_clocks(end_cpu - start_cpu);
}

/* Recursive function for merge-insertion sort. */

void merge_insertion_sort_recursive(monster *list, int low_index, int high_index, 
		int *comparisons, int *copies, int *block_copies, int *mallocs,
		int use_name, int use_weight)
{
	// YOUR CODE GOES HERE.
}

/* Implement merge sort. */

void merge_insertion_sort(monster *list, int n, int use_name, int use_weight)
{
	int comparisons = 0;
	int copies = 0;
	int block_copies = 0;
	int mallocs = 0;
	clock_t start_cpu, end_cpu;

	printf("Merge-insertion sort %d monsters...\n", n);

	start_cpu = clock();
	merge_insertion_sort_recursive(list, 0, n-1, &comparisons, &copies, &block_copies, &mallocs,
			use_name, use_weight);
	end_cpu = clock();

	printf("Sort complete with %d comparisons, %d block copies, %d total copies, %d mallocs.\n", comparisons, block_copies, copies, mallocs);
	print_clocks(end_cpu - start_cpu);
}

/* Main program. */

void run_all_sorts(int n, int only_fast, int use_name, int use_weight) {
	monster *our_list = make_some_monsters(n);
	monster *our_unsorted_list = malloc(sizeof(monster) * n);

	printf("SORT SET: n = %d, %s, by %s\n\n", n, only_fast ? "fast sorts only" : "all sorts", use_name ? "name" : "weight");

	if(only_fast == 0) {
		memcpy(our_unsorted_list, our_list, sizeof(monster) * n);
		bubble_sort(our_unsorted_list, n, use_name, use_weight);
		check_monster_sort(our_unsorted_list, n, use_name, use_weight);

		memcpy(our_unsorted_list, our_list, sizeof(monster) * n);
		selection_sort(our_unsorted_list, n, use_name, use_weight);
		check_monster_sort(our_unsorted_list, n, use_name, use_weight);

		memcpy(our_unsorted_list, our_list, sizeof(monster) * n);
		insertion_sort(our_unsorted_list, n, use_name, use_weight);
		check_monster_sort(our_unsorted_list, n, use_name, use_weight);
	}

	memcpy(our_unsorted_list, our_list, sizeof(monster) * n);
	quick_sort(our_unsorted_list, n, use_name, use_weight);
	check_monster_sort(our_unsorted_list, n, use_name, use_weight);

	memcpy(our_unsorted_list, our_list, sizeof(monster) * n);
	merge_sort(our_unsorted_list, n, use_name, use_weight);
	check_monster_sort(our_unsorted_list, n, use_name, use_weight);

	memcpy(our_unsorted_list, our_list, sizeof(monster) * n);
	merge_insertion_sort(our_unsorted_list, n, use_name, use_weight);
	check_monster_sort(our_unsorted_list, n, use_name, use_weight);

	printf("SORT SET COMPLETE\n\n");

	free(our_list);
	free(our_unsorted_list);
}

int main(void) {
	run_all_sorts(50, 0, 0, 1);
	run_all_sorts(50, 0, 1, 0);
	run_all_sorts(500, 0, 0, 1);
	run_all_sorts(500, 0, 1, 0);
	run_all_sorts(5000, 0, 0, 1);
	run_all_sorts(5000, 0, 1, 0);
	run_all_sorts(50000, 1, 0, 1);
	run_all_sorts(50000, 1, 1, 0);
	run_all_sorts(500000, 1, 0, 1);
	run_all_sorts(500000, 1, 1, 0);
}
