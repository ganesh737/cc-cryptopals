str = "The, of, and, to, in, a, is, that, be, it, by, are, for, was, as, he, with, on, his, at, which, but, from, has, this, will, one, have, not, were, or, all, their, an, I, there, been, many, more, so, when, had, may, today, who, would, time, we, about, after, dollars, if, my, other, some, them, being, its, no, only, over, very, you, into, most, than, they, day, even, made, out, first, great, must, these, can, days, every, found, general, her, here, last, new, now, people, public, said, since, still, such, through, under, up, war, well, where, while, years, before, between, country, debts, good, him, interest, large, like, make, our, take, upon, what"

split_val = str.split(", ")

print '","'.join(str.split(", ")[::-1])