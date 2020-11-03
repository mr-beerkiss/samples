const paid1 = 88168;
const paid2 = 118767;

const total = paid1 + paid2;

function formatCurrency(amt: number): string {
	const cents = amt % 100;
	const dollars = amt / 100 | 0;

	return `$${dollars}.${cents}`;
}


console.log(`Amount paid: ${formatCurrency(total)}`);


const outstandingDays = 1 + 21 - 16;
const rentPerDay = 243300 * 12 / 365;

const outstandingOct = outstandingDays * rentPerDay;

console.log(`Amount paid: ${formatCurrency(outstandingOct)}`);
