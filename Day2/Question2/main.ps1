$ValidCount = 0

foreach ($Line in Get-Content -Path ..\input.txt) {
    # Use Regex to get all of the components of the input string.
    if ($Line -match '(?<FirstIndex>\d+)-(?<SecondIndex>\d+) (?<Letter>\w): (?<Password>\w+)') {
        # Needs to only match in one of the places, not both. XOR is what we want to achieve this.
        if (($Matches.Password[$Matches.FirstIndex-1] -eq $Matches.Letter) -xor 
        ($Matches.Password[$Matches.SecondIndex-1] -eq $Matches.Letter)) {
            $ValidCount++
        }
    }
}

Write-Host "Final Count: $ValidCount"