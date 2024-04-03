#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Wrong number of arguments" >&2
    exit 1
fi

# Function to clean up rules
clean_rule() {
    local rule="$1"
    rule=$(sed 's/ //g' <<< "$rule")
    rule=$(sed 's/#.*//' <<< "$rule")
    rule=$(sed '/^$/d' <<< "$rule")
    rule=$(sed 's/,\{2,\}/,/g' <<< "$rule")
    rule=$(sed 's/^,//g' <<< "$rule")
    echo "$rule"
}

# Array to store the valid packets
valid_packets=()

# Read input packets
while read -r packet; do
    # Clean the packet
    packet=$(sed 's/ //g' <<< "$packet")
    # Read each rule and apply it to the packet
    while read -r complex_rule; do
        IFS=',' read -ra rules <<< "$(clean_rule "$complex_rule")"
        if [[ "${#rules[@]}" -eq 4 ]]; then
            # Check if the packet passes all four sub-rules
            if ./firewall.exe "${rules[0]}" <<< "$packet" | \
               ./firewall.exe "${rules[1]}" | \
               ./firewall.exe "${rules[2]}" | \
               ./firewall.exe "${rules[3]}" | grep -q 'ALLOW'; then
               valid_packets+=("$packet")
               break
            fi
        fi
    done
done

# Sort the valid packets and remove duplicates
sorted_unique_packets=$(printf "%s\n" "${valid_packets[@]}" | sort -u)

# Print the sorted and unique packets
printf "%s\n" "$sorted_unique_packets"
