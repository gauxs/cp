export const TIER_ORDER = ["beginner", "intermediate", "advanced"];

export function formatTier(tier) {
  if (!tier) return "";
  return tier.charAt(0).toUpperCase() + tier.slice(1);
}

export function primaryTier(difficulties) {
  return difficulties?.[0] ?? "";
}
