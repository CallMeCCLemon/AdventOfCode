$ValidCount = 0
foreach ($Line in Get-Content -Path ..\input.txt) {
    
    # Use Regex to get all of the components of the input string.
    if ($Line -match '(?<LowerRange>\d+)-(?<UpperRange>\d+) (?<Letter>\w): (?<Password>\w+)') {
        # Split on the target character then count how many splits were made (i.e. how many instances)
        # of the character there were.
        $LetterCount = $Matches.Password.split($Matches.Letter).Length - 1

        # Check if the occurence count is within the range and increment the valid password count if so.
        if (($LetterCount -ge $Matches.LowerRange) -and ($LetterCount -le $Matches.UpperRange)) {
            $ValidCount++
        } 
    }
}

Write-Host "Final Count: $ValidCount"