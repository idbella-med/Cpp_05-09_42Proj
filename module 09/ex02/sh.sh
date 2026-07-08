 #!/bin/bash

# for i in {1..1000}; do
#     nums=$(jot -r 3000 1 1000 | tr '\n' ' ')

#     ./PmergeMe $nums > out.txt

#     after=$(grep "After:" out.txt | sed 's/After: //' | tr ' ' '\n')
#     sorted=$(echo "$after" | sort -n)

#     if [ "$after" != "$sorted" ]; then
#         echo "FAIL on test $i"
#         echo "Input: $nums"
#         cat out.txt
#         exit 1
#     fi
# done

# echo "All tests passed!"

for n in {1..5}; do
    nums=$(jot -r $n 1 100)
    ./PmergeMe $nums
done