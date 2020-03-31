package main

type Type int

const (
	None Type = iota
	Literal
	Dot
	Asterisk
	All
)

type Token struct {
	Type Type
	Data string
}

var (
	tokens []Token
	input  = ""
)

func initTokens(s string) {
	t := Token{}
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case '*':
			switch t.Type {
			case Literal:
				t2 := Token{
					Type: Asterisk,
					Data: t.Data[len(t.Data)-1:],
				}
				t.Data = t.Data[:len(t.Data)-1]
				if len(t.Data) > 0 {
					tokens = append(tokens, t)
				}
				t = t2
			case Dot:
				t.Type = All
			}
		case '.':
			switch t.Type {
			case None:
				t.Type = Dot
			case Literal:
				tokens = append(tokens, t)
				t.Type = Dot
			case Dot:
				tokens = append(tokens, t)
			case Asterisk:
				tokens = append(tokens, t)
				t.Type = Dot
			case All:
				tokens = append(tokens, t)
				t.Type = Dot
			}
		default:
			switch t.Type {
			case None:
				t.Type = Literal
				t.Data = string(s[i])
			case Literal:
				t.Data += string(s[i])
			case Dot:
				tokens = append(tokens, t)
				t.Type = Literal
				t.Data = string(s[i])
			case Asterisk:
				tokens = append(tokens, t)
				t.Type = Literal
				t.Data = string(s[i])
			case All:
				tokens = append(tokens, t)
				t.Type = Literal
				t.Data = string(s[i])
			}
		}
	}
	tokens = append(tokens, t)
}

func checkWithTokens(i int, j int) bool {
	if i == len(input) && j == len(tokens) {
		return true
	} else if i == len(input) {
		for j < len(tokens) {
			if tokens[j].Type == All || tokens[j].Type == Asterisk {
				j++
			} else {
				return false
			}
		}
		return true
	} else if j == len(tokens) {
		return false
	}
	t := tokens[j]
	switch t.Type {
	case Literal:
		if len(input)-i < len(t.Data) {
			return false
		}
		for k := 0; k < len(t.Data); k++ {
			if input[i] != t.Data[k] {
				return false
			}
			i++
		}
		return checkWithTokens(i, j+1)
	case Dot:
		return checkWithTokens(i+1, j+1)
	case Asterisk:
		c := t.Data[0]
		old := i
		for i < len(input) && input[i] == c {
			i++
			if checkWithTokens(i, j+1) {
				return true
			}
		}
		i = old
		return checkWithTokens(i, j+1)
	case All:
		for k := i; k < len(input)+1; k++ {
			if checkWithTokens(k, j+1) {
				return true
			}
		}
		return false
	}
	return false
}

func isMatch(s string, p string) bool {
	if s == "" && p == "" {
		return true
	}
	input = s
	tokens = make([]Token, 0)
	initTokens(p)
	//for i, t := range tokens {
	//	fmt.Print(i, " ")
	//	if t.Type == Literal ||  t.Type == Asterisk {
	//		fmt.Println(t.Type, t.Data)
	//	} else {
	//		fmt.Println(t.Type)
	//	}
	//}
	return checkWithTokens(0, 0)
}

func main() {
	//println(isMatch("aa", "a"))
	//println(isMatch("aa", "a*"))
	//println(isMatch("ab", ".*"))
	//println(isMatch("aab", "c*a*b"))
	//println(isMatch("mississippi", "mis*is*p*."))
	//println(isMatch("mississippi", "mis*is*ip*."))
	//println(isMatch("a", "ab*"))
	println(isMatch("bbbba", ".*a*a"))
}
