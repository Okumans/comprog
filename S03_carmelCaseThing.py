def toCarmelCase(string: str) -> str:
    words: list[str] = string.replace("?", "-").lstrip("-").split("-")
    result: str = words[0].lower()

    for word in words[1:]:
        result += word.capitalize()

    return result


if __name__ == "__main__":
    user_input: str = input()
    print(toCarmelCase(user_input))
