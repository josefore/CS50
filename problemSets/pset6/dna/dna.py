import sys
import csv


def main():
    # Check for correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py [STR.csv] [DNA.txt]")

    persons = []
    str_keys = []

    # Load csv file of individuals' STRs
    with open(sys.argv[1]) as database:
        reader = csv.DictReader(database)
        for row in list(reader):
            # Get the list of keys to convert values into ints
            prov_keys = list(row.keys())
            str_keys = prov_keys[1:]
            for k in str_keys:
                row[k] = int(row[k])

            persons.append(row)

    dna_info = ""
    # Load txt file of DNA sequence
    with open(sys.argv[2]) as sequence:
        lector = csv.reader(sequence)
        dna_list = list(lector)
        dna = dna_list[0]
        dna_info = dna[0]

    srt_record = str_chains(dna_info, str_keys)
    guilty = compare(srt_record, persons, str_keys)

    print(guilty)


# Compute longest SRT chains
def str_chains(dna_info, str_keys):
    oa_record = {}  # Dict where repetitions record (overall)
    # Loop until the sequence ends (checar si no es endless)
    for s in str_keys:
        history = []  # List where location history will be recorded
        loc = 0
        p = 0  # Changes value after first iteration to count first position

        while True:
            loc = dna_info.find(s, loc + p)
            if loc == - 1:
                break

            history.append(loc)

            if p == 0:
                p += 1

        record = []
        rec = 1

        for i in range(len(history)):
            if i == len(history) - 1:  # Control out of range exception
                record.append(rec)
                break
            if history[i + 1] - history[i] == len(s):
                rec = rec + 1
            else:
                record.append(rec)
                rec = 1

        record.sort(reverse=True)
        if len(record) > 0:
            oa_record[s] = record[0]
        else:
            oa_record[s] = 0

    return oa_record


# Compare data, returns name of matched person
def compare(srt_record, persons, str_keys):
    for person in persons:
        match = True
        for s in str_keys:
            if srt_record[s] != person[s]:
                match = False
                break

        if match:
            return person["name"]
    return "No match"


# Run Main
main()