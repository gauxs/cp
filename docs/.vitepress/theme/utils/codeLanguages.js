/** Supported code-tab languages. Extend when adding multi-language topic files. */
export const CODE_LANGUAGES = [
  { id: "cpp", label: "C++" },
];

export function languageLabel(id) {
  return CODE_LANGUAGES.find((lang) => lang.id === id)?.label ?? id;
}
