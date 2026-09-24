/** Site-wide language options (library tab + code panel). */
export const SITE_LANGUAGES = [
  { id: "cpp", label: "C++" },
  { id: "java", label: "Java" },
  { id: "go", label: "Go" },
];

/** @deprecated use SITE_LANGUAGES */
export const CODE_LANGUAGES = SITE_LANGUAGES;

export const DEFAULT_SITE_LANGUAGE = "cpp";

export function languageLabel(id) {
  return SITE_LANGUAGES.find((lang) => lang.id === id)?.label ?? id;
}
