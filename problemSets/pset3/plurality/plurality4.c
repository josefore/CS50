#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void sort(int m);
bool winner(int n);
void print(int n);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int m = 0;
    // Count max num of voters
    for (int k = 0; k < candidate_count; k++)
    {
        m = m + candidates[k].votes;
    }
    sort(m);
}

// Calculate score of winner
void sort(int m)
{
    for (int n = m; n > 0; n--)
    {
        if (winner(n))
        {
            return;
        }
    }
}

// Match max score to votes
bool winner(int n)
{
    for (int p = 0; p < candidate_count; p++)
    {
        if (candidates[p].votes == n)
        {
            print(n);
            return true;
        }
    }
    return false;
}

//Print names of candidates whose votes match
void print(int n)
{
    for (int q = 0; q < candidate_count; q++)
    {
        if (candidates[q].votes == n)
        {
            printf("%s\n", candidates[q].name);
        }
    }
    return;
}