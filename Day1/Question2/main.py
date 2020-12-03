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

    # Start at index=2, iterate through the sorted list incrementing the final index,
    # subtract the value from the target, then find the new target from the sublist.
    i = 2
    first_index = -1
    second_index = -1
    third_index = -1

    while i < len(list_of_values):
        idx_one, idx_two = find_target_sum(list_of_values[0: i], target_sum - list_of_values[i])
        if idx_one is not None:
            first_index = idx_one
            second_index = idx_two
            third_index = i
            break
        else:
            i += 1

    print("The final values are {}, {} and {}. Their sum is {} and their product is {}."
          .format(list_of_values[first_index],
                  list_of_values[second_index],
                  list_of_values[third_index],
                  list_of_values[first_index] + list_of_values[second_index] + list_of_values[third_index],
                  list_of_values[first_index] * list_of_values[second_index] * list_of_values[third_index]))


def find_target_sum(input_list: list, target: int):
    start_index = 0
    end_index = len(input_list) - 1
    # The pointer at the end is much larger than the pointer at the start.
    # If the sum is over 2020, we can decrement the larger pointer to point to a smaller number.
    # If the sum is less than 2020, we should increment the smaller pointer to be larger.
    # Repeat until we find the solution. This is O(n) complexity.
    while end_index > start_index:
        current_sum = input_list[start_index] + input_list[end_index]
        if current_sum == target:
            return start_index, end_index
        elif current_sum > target:
            end_index -= 1
        else:
            start_index += 1

    return None, None


if __name__ == '__main__':
    main('../input.txt', 2020)
