$firstLine = Get-Content -Path "InputArea.txt" -TotalCount 1
$inputDataStr = $firstLine -split " "
$x0 = [double]$inputDataStr[0]
$xn = [double]$inputDataStr[1]
$count = Read-Host "Enter receivers amount"
if (-not ($count -match '^\d+$')) {
	Write-Host "Unexpected value" -ForegroundColor Red
	exit
}
$count = [int]$count
if ($count -le 0) {
	Write-Host "Value must be non-negative" -ForegroundColor Red
	exit
}
$step = ($xn + $x0) / ($count - 1)
$coordinates = @()
for ($i = 0; $i -lt $count; $i++) {
	$x = $x0 + ($i * $step)
	$coordinates += "{0:N2}" -f $x
}
$output = "$count`r`n" + ($coordinates -join " 0 0`r`n") + (" 0 0")
$output | Out-File -FilePath "Receivers.txt" -Encoding utf8
