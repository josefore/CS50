#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }
    tabulate();

    for (int g = 0; g < candidate_count; g++)
    {
        printf("%s votes: %i\n", candidates[g].name, candidates[g].votes);
    }
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
   for (int a = 0; a < candidate_count; a++)
   {
       if (strcmp(name, candidates[a].name) == 0)
       {
           preferences[voter][rank] = a;
           return true;
       }
   }
   return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop over preferences to update cadidates votes
    for (int voter_tab = 0; voter_tab < voter_count; voter_tab++)
    {
        for (int rank_tab = 0; rank_tab < candidate_count; rank_tab++)
        {
            if (!candidates[preferences[voter_tab][rank_tab]].eliminated)
            {
                candidates[preferences[voter_tab][rank_tab]].votes++;
                break;
            }
        }
    }

    return;
}
