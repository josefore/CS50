import cs50


def blocks(i, h):
    for j in range(i + 1):
        print('#', end='')


def main():
    h = 0
    while h < 1 or h > 8:
        h = cs50.get_int("Height: ")

    for i in range(h):
        for k in range(h - i - 1, 0, - 1):
            print(' ', end='')

        blocks(i, h)
        print('  ', end='')
        blocks(i, h)
        print('\n', end='')


main()