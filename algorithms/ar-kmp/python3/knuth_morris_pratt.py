#Python program for KMP Algorithm
def LPSArray(pat, M, lps):
	lenn = 0
	i = 1
	while i < M:
		if pat[i]== pat[lenn]:
			lenn += 1
			lps[i] = lenn
			i += 1
		else:
			if lenn != 0:
				lenn = lps[lenn-1]		
			else:
				lps[i] = 0
				i += 1

def KMP(pat, txt):
	M = len(pat)
	N = len(txt)

	# create lps[] that will hold the longest prefix suffix values for pattern
	lps = [0]*M
	j = 0

	# Preprocess the pattern (calculate lps[] array)
	LPSArray(pat, M, lps)

	i = 0 # index for txt[]
	while i < N:
		if pat[j] == txt[i]:
			i += 1
			j += 1

		if j == M:
			print ("Found pattern at index " + str(i-j))
			j = lps[j-1]

		# mismatch after j matches
		elif i < N and pat[j] != txt[i]:
			if j != 0:
				j = lps[j-1]
			else:
				i += 1

txt = "ABABDABACDABABCABAB"
pat = "ABABCABAB"
KMP(pat, txt)


