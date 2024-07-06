# Script Requirements:
#   - Declare an indexed array containing at least 5 elements (e.g., names of cities).
#   - Print the entire array
#   - Print the length of the array
#   - Use a loop to iterate through the array and print each element.

cities=("New Mexico" "Cairo" "Alexandria" "London" "San Francisco")

# Print entire array
echo ${cities[@]}

# Print array length
echo ${#cities[@]}

# Print each element
for city in ${cities[@]}
do
    echo $city
done