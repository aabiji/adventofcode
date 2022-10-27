

def score_count(x):
    level, score = 1, 0
    for i in x:
        if i == "{":
            score += level
            level += 1
        if i == "}": level -= 1
    return score


