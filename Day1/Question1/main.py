def main(input_text_file: str, target_sum: int) -> None:
    """
    Determines from an input file what two numbers add up to a target sum.
    It then prints the values and their product.

    :param input_text_file: The text file with input values.
    :param target_sum: The sum which should be added up to.
    :return: None
    """
    list_of_values = []
    with open(input_text_file) as input_file:
        for line in input_file:
            list_of_values.append(int(line))

    # Sort the list.
    list_of_values.sort()

    end_pointer = len(list_of_values) - 1
    start_pointer = 0

    # The pointer at the end is much larger than the pointer at the start.
    # If the sum is over 2020, we can decrement the larger pointer to point to a smaller number.
    # If the sum is less than 2020, we should increment the smaller pointer to be larger.
    # Repeat until we find the solution. This is O(n) complexity.
    while end_pointer > start_pointer:
        current_sum = list_of_values[start_pointer] + list_of_values[end_pointer]
        if current_sum == target_sum:
            break
        elif current_sum > target_sum:
            end_pointer -= 1
        elif current_sum < target_sum:
            start_pointer += 1

    print("The final values are {} and {}. Their sum is {} and their product is {}."
          .format(list_of_values[start_pointer],
                  list_of_values[end_pointer],
                  list_of_values[start_pointer] + list_of_values[end_pointer],
                  list_of_values[start_pointer] * list_of_values[end_pointer]))


if __name__ == '__main__':
    main('../input.txt', 2020)
