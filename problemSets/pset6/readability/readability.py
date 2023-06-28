from cs50 import get_string


def main():
    # Prompt user for input
    text = get_string("Text: ")

    # Number of letters for every 100 words
    l = letters_num(text) / words_num(text) * 100

    # Number of sentences for every 100 words
    s = sentence_num(text) / words_num(text) * 100

    # Calculate index
    index = 0.0588 * l - 0.296 * s - 15.8

    # Display output
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")


# Calculate number of letters - return int
def letters_num(text):
    num = 0
    for c in text:
        if c.isalpha():
            num += 1

    return num


# Calculate number of words - return int
def words_num(text):
    num = 0
    for c in text:
        if c == ' ':
            num += 1

    return num + 1


# Calculate number of sentences - return int
def sentence_num(text):
    num = 0
    for c in text:
        if c == '.' or c == '!' or c == '?':
            num += 1

    return num


# Run main
main()