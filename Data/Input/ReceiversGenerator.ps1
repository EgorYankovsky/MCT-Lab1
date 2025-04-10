$numericalOutputFormat = New-Object System.Globalization.CultureInfo("en-US")
$x0 = Read-Host "Enter x0: "
$x0 = [double]$x0
$xn = Read-Host "Enter xn: "
$xn = [double]$xn
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
$step = ($xn - $x0) / ($count - 1)
$step = [double]$step
$coordinates = @()
for ($i = 0; $i -lt $count; $i++) {
	$x = $x0 + ($i * $step)
	$coordinates += $x.ToString("F2", $numericalOutputFormat)
}
$output = "$count`r`n" + ($coordinates -join " 0 0`r`n") + (" 0 0")
$output | Out-File -FilePath "Receivers.txt" -Encoding utf8
