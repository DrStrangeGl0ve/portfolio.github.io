# Read the input from keyboard to make the list
number_list = input().split()
# Read the input from keyboard to make the eligible range of numbers
limits = input().split()

# Convert input strings to integers
list_as_ints = list(map(int, number_list))
# Sets the upper and lower limits for the range.
lower_limit = int(limits[0])
upper_limit = int(limits[1])

# Checks through the range of numbers and adds the numbers to a new list if they are within the limits.
nums_in_range = [str(num) for num in list_as_ints if lower_limit <= num <= upper_limit]

# Print the result
print(','.join(nums_in_range) + ',', end='')